// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(test1, test_wait) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  std::string expected_state = "Off";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test2, test_wait) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  std::string expected_state = "Wait";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test3, test_accept) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  std::string expected_state = "Accept";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test4, test_accept) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.cancel();
  std::string expected_state = "Wait";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test5, test_accept) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.choice(1);
  std::string expected_state = "Check";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test6, test_check) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.choice(1);
  std::string expected_state = "Check";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test7, test_check) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.coin(150);
  automat.choice(1);
  automat.check();
  std::string expected_state = "Cook";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test8, test_check) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.choice(1);
  automat.check();
  std::string expected_state = "Accept";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test9, test_check) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.choice(1);
  automat.cancel();
  std::string expected_state = "Wait";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test10, test_cook) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.coin(150);
  automat.choice(1);
  automat.check();
  automat.cook();
  std::string expected_state = "Cook";
  EXPECT_EQ(automat.getState(), expected_state);
}

TEST(test11, test_cook) {
  std::string menu[] = { "Latte", "Espresso macchiato", "Americano"};
  int prices[] = {100, 110, 80};
  Automata automat(menu, prices, 3);
  automat.on();
  automat.coin(100);
  automat.coin(150);
  automat.choice(1);
  automat.check();
  automat.cook();
  automat.finish();
  std::string expected_state = "Wait";
  EXPECT_EQ(automat.getState(), expected_state);
}

