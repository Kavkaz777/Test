#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/text.h"
}

TEST(showrevevenTest, p1) {
   char *a = (char*)malloc(1);
   a[0]=0;
   text txt = create_text();
   showreveven(txt);
   SUCCEED();
}

TEST(showrevevenTest, p2) {
    text txt = create_text();
    load(txt, (char*)"/home/01/mamedovi/Test/gtest-master/app/input.txt");
    showreveven(txt);
    SUCCEED();
}

//TEST(fibonachiTest, negative) {
//    ASSERT_EQ(fibonachi(-1), 0);
//}

#endif // FIBONACHI_H
