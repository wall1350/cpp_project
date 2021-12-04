#include "../src/ellipse.h"

TEST(Ellipse, TestEllipsePerimeter) {
  Ellipse ellipse(7, 4);
  ASSERT_EQ(37.133, ellipse.perimeter());
}

TEST(Ellipse, TestEllipseArea) {
  Ellipse ellipse(7, 4);
  ASSERT_EQ(87.965, ellipse.area());
}

TEST(Ellipse, TestEllipseInfo) {
  Ellipse ellipse(7, 4);
  ASSERT_EQ("Ellipse (7.000, 4.000)", ellipse.info());
}

TEST(Ellipse, TestEllipseFail) {
  try{
      Ellipse ellipse(-1.2820, 0.301);// 我預期這裡會失敗，程式將會跳到下方的catch區塊，而不是執行下一行  
      FAIL(); //如果執行了這一行，代表測試失敗，因為我原本預期這裡會產生Exception，並跳到下方的catch區塊

    }catch(std::string e){
      EXPECT_EQ(std::string("This is not an ellipse!"), e);
    }
}
