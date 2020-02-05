#include "Signal.h"

#include <iostream>

#include <gtest/gtest.h>

namespace sigtest
{
  struct NonCopyable{
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator = (const NonCopyable&) = delete;
    NonCopyable(NonCopyable&&) = default;
    NonCopyable& operator = (NonCopyable&&) = default;
  };

  struct NonMovable{
    NonMovable() = default;
    NonMovable(const NonMovable&) = default;
    NonMovable& operator = (const NonMovable&) = default;
    NonMovable(NonMovable&&) = delete;
    NonMovable& operator = (NonMovable&&) = delete;
  };

  struct NonMovableAndCopyable{
    NonMovableAndCopyable() = default;
    NonMovableAndCopyable(const NonMovableAndCopyable&) = delete;
    NonMovableAndCopyable& operator = (const NonMovableAndCopyable&) = delete;
    NonMovableAndCopyable(NonMovableAndCopyable&&) = delete;
    NonMovableAndCopyable& operator = (NonMovableAndCopyable&&) = delete;
  };

} // namespace sigtest


void callback ( int param ) {
    std::cout << "Here is your Integer : " << param << std::endl;
}

int callback2 (int x){
    return x+1;
}

int callback3 (int x){
    return x*3;
}

TEST(TestReturnVoid, BasicTestsDiscard){
    sig::Signal<void(int)> sig ;
    // connect a simple function
    sig.connectSlot ( callback );
    // connect a lambda function
    int res = 0;
    std::size_t indexScnd = sig.connectSlot ([& res ]( int x ) { res = x ; });
    // emit the signal
    sig.emitSignal(1);

    EXPECT_EQ(1, res);

    EXPECT_EQ(sig.funcs.size(), 2u);
    sig.disconnectSlot(indexScnd);
    EXPECT_EQ(sig.funcs.size(), 1u);

    sig.emitSignal(1);

    EXPECT_EQ(res, 1);
}


TEST(TestReturnVoid, NoArgument){
    sig::Signal<void(void)> sig;
    sig.connectSlot ([]() {printf("Testing\n");} );
    int res = 0;
    sig.connectSlot ([& res ]() { res = 125; });
    sig.emitSignal();
    EXPECT_EQ(res,125);
    EXPECT_NO_THROW(sig.c.result());
}

TEST(TestReturnVoid, MultipleArguments){
    sig::Signal<void(int, int)> sig;
    sig.connectSlot ([](int x, int y) {printf("J'ai un %d et un %d\n",x,y);} );
    int res = 0;
    sig.connectSlot ([& res ](int x, int y) { res = x*y; });
    sig.emitSignal(2,3);
    EXPECT_EQ(res,6);
    EXPECT_NO_THROW(sig.c.result());
}

TEST(TestReturnVoid, MultipleDifferentArguments){
    sig::Signal<void(int, char)> sig;
    sig.connectSlot ([](int x, char alpha) {printf("J'ai un %d et un %c\n",x,alpha);} );
    int res = 0;
    sig.connectSlot ([& res ](int x, int alpha) { res = x*(int)alpha; });
    sig.emitSignal(2,'a');
    EXPECT_EQ(res,194);
    EXPECT_NO_THROW(sig.c.result());
}

TEST(TestReturnInt, BasicTestsLastCombiner){
    sig::Signal<int(int), sig::LastCombiner<int>> sig;
    sig.connectSlot(callback2);
    sig.emitSignal(1);
    EXPECT_EQ(sig.c.result(), 2);
}

TEST(TestReturnInt, MultipleCallBackLastCombiner){
    sig::Signal<int(int), sig::LastCombiner<int>> sig;
    sig.connectSlot(callback2);
    sig.connectSlot(callback3);
    sig.emitSignal(2);
    EXPECT_EQ(sig.c.result(), 6);
}

TEST(TestReturnInt, BasicTestVectorCombiner){
    sig::Signal<int(int), sig::VectorCombiner<int>> sig;
    sig.connectSlot(callback2);
    sig.emitSignal(2);
    EXPECT_EQ(sig.c.result().size(), 1u);
    EXPECT_EQ(sig.c.result()[0], 3);
}

TEST(TestReturnInt, MultipleCallbacksVectorCombiner){
    sig::Signal<int(int), sig::VectorCombiner<int>> sig;
    sig.connectSlot(callback2);
    sig.connectSlot(callback3);
    sig.emitSignal(2);
    EXPECT_EQ(sig.c.result().size(), 2u);
    EXPECT_EQ(sig.c.result()[0], 3);
    EXPECT_EQ(sig.c.result()[1], 6);
}

std::vector<int> callback4(int x,int y,int z){
    return {x,y,z};
}
std::vector<int> callback5(int x,int y,int z){
    return {z,y,x};
}

TEST(TestReturnVector, BasicTestLastCombiner){
    sig::Signal<std::vector<int>(int,int,int),sig::LastCombiner<std::vector<int>>> sig;
    sig.connectSlot(callback4);
    sig.emitSignal(2,4,8);
    EXPECT_EQ(sig.c.result().size(), 3u);
    EXPECT_EQ(sig.c.result()[0],2);
    EXPECT_EQ(sig.c.result()[1],4);
    EXPECT_EQ(sig.c.result()[2],8);
}

TEST(TestReturnVector, BasicTestVectorCombiner){
    sig::Signal<std::vector<int>(int,int,int),sig::VectorCombiner<std::vector<int>>> sig;
    sig.connectSlot(callback4);
    sig.connectSlot(callback5);
    sig.emitSignal(2,4,8);
    EXPECT_EQ(sig.c.result().size(), 2u);
    EXPECT_EQ(sig.c.result()[0][0], 2);
    EXPECT_EQ(sig.c.result()[0][1], 4);
    EXPECT_EQ(sig.c.result()[0][2], 8);
    EXPECT_EQ(sig.c.result()[1][0], 8);
    EXPECT_EQ(sig.c.result()[1][1], 4);
    EXPECT_EQ(sig.c.result()[1][2], 2);

}

sigtest::NonMovable callback6(){
    return sigtest::NonMovable();
}
TEST(TestNonMovable, DiscardCombiner){
    sig::Signal<sigtest::NonMovable(void)> sig;
    sig.connectSlot(callback6);
    sig.emitSignal();
    EXPECT_NO_THROW(sig.c.result());
}

/*TEST(TestNonMovable, LastCombiner){
    sig::Signal<sigtest::NonMovable(sigtest::NonMovable),sig::LastCombiner<sigtest::NonMovable>> sig;
    sigtest::NonMovable noMove;
    sig.connectSlot([&noMove](sigtest::NonMovable x){noMove = x;});
    sigtest::NonMovable tmp;
    sig.emitSignal(tmp);
    EXPECT_EQ(noMove, tmp);
}*/

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
