#include "pch.h"
#include "LoginFunctions.h"
#include <gtest/gtest.h>

TEST(EmailValidation, ValidEmail) {
    EXPECT_TRUE(isValidEmail("test@test.com"));
    EXPECT_TRUE(isValidEmail("example@example.com"));
    EXPECT_TRUE(isValidEmail("example@example.co.uk"));
    EXPECT_TRUE(isValidEmail("user.name+tag@sub.domain.com"));
}

TEST(EmailValidation, InvalidEmail) {
    EXPECT_FALSE(isValidEmail("example.com"));
    EXPECT_FALSE(isValidEmail("user@.com"));
    EXPECT_FALSE(isValidEmail("user@domain"));
    EXPECT_FALSE(isValidEmail("@missingusername.com"));
    EXPECT_FALSE(isValidEmail("invalid-email@"));
}

// Checks if the file contains the email

TEST(FileEmailCheck, EmailExists) {
    EXPECT_TRUE(isEmailInUsersFile("test@test.com"));
}

TEST(FileEmailCheck, EmailDoesNotExist) {
    EXPECT_FALSE(isEmailInUsersFile("est@test.com"));
    EXPECT_FALSE(isEmailInUsersFile("nonexistentemail@gmail.com"));
}


// Password validation testing

TEST(PasswordCheck, CorrectPassword) {
    EXPECT_TRUE(isPasswordCorrect("test@test.com", "1234"));
    EXPECT_TRUE(isPasswordCorrect("mihail@gmail.com", "ABCD"));
}

TEST(PasswordCheck, IncorrectPassword) {
    EXPECT_FALSE(isPasswordCorrect("test@test.com", "wrongpassword"));
    EXPECT_FALSE(isPasswordCorrect("test@test.com", "234"));
    EXPECT_FALSE(isPasswordCorrect("test@test.com", "X1234"));
    EXPECT_FALSE(isPasswordCorrect("test@test.com", "}"));
    EXPECT_FALSE(isPasswordCorrect("mihail@gmail.com", "Abcd"));
    EXPECT_FALSE(isPasswordCorrect("mihail@gmail.com", "aBcd"));
    EXPECT_FALSE(isPasswordCorrect("mihail@gmail.com", "abcd"));
    EXPECT_FALSE(isPasswordCorrect("mihail@gmail.com", "wrongpassword"));
}

TEST(PasswordCheck, EmptyEmailAndPassword) {
    EXPECT_FALSE(isPasswordCorrect("", ""));
}

TEST(PasswordCheck, EmailNotFound) {
    EXPECT_FALSE(isPasswordCorrect("test@test.com", "anyPassword"));
    EXPECT_FALSE(isPasswordCorrect("nonexistentemail@gmail.com", "anyPassword"));
}

// Test scenarios

// Scenario 1. 1>2>2B>3>3B>4>4B>5>5B>6

TEST(LoginScenario, PositiveScenario) {
    string email = "test@test.com";
    string password = "1234";
    EXPECT_FALSE(email.empty());
    EXPECT_FALSE(password.empty());
    EXPECT_TRUE(isValidEmail(email));
    EXPECT_TRUE(isEmailInUsersFile(email));
    EXPECT_TRUE(isPasswordCorrect(email, password));
}

// Scenario 2. 1>2>2B>3>3B>4>4B>5>5A>1

TEST(LoginScenario, EmailNotFoundInFile) { // Scenario 2.1.
    string email = "nonexistentemail@gmail.com";
    string password = "1234";
    EXPECT_FALSE(email.empty());
    EXPECT_FALSE(password.empty());
    EXPECT_TRUE(isValidEmail(email));
    EXPECT_FALSE(isEmailInUsersFile(email));
    EXPECT_FALSE(isPasswordCorrect(email, password));
}


TEST(LoginScenario, IncorrectPassword) { // Scenario 2.2.
    string email = "test@test.com";
    string password = "abcde";
    EXPECT_FALSE(email.empty());
    EXPECT_FALSE(password.empty());
    EXPECT_TRUE(isValidEmail(email));
    EXPECT_TRUE(isEmailInUsersFile(email));
    EXPECT_FALSE(isPasswordCorrect(email, password));
}

TEST(LoginScenario, EmailNotFoundInFileAndIncorrectPassword) { // Scenario 2.3.
    string email = "nonexistentemail@gmail.com";
    string password = "abcde";
    EXPECT_FALSE(email.empty());
    EXPECT_FALSE(password.empty());
    EXPECT_TRUE(isValidEmail(email));
    EXPECT_FALSE(isEmailInUsersFile(email));
    EXPECT_FALSE(isPasswordCorrect(email, password));
}

// Scenario 3. 1>2>2B>3>3B>4>4A>1

TEST(LoginScenario, InvalidEmail) {
    string email = "user@.com";
    string password = "1234";
    EXPECT_FALSE(email.empty());
    EXPECT_FALSE(password.empty());
    EXPECT_FALSE(isValidEmail(email));
}

// Scenario 4. 1>2>2B>3>3A>1
TEST(LoginScenario, EmptyPassword) {
    string email = "test@test.com";
    string password = "";
    EXPECT_FALSE(email.empty());
    EXPECT_TRUE(password.empty());
}


// Scenario 5. 1>2>2A>1

TEST(LoginScenario, EmptyEmail) {
    string email = "";
    string password = "1234";
    EXPECT_TRUE(email.empty());
    EXPECT_FALSE(password.empty());
}
