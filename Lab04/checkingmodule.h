#pragma once

#include <string>
#include <iostream>
#include <cmath>

void deposit(float &account, float amount);

char MainMenu();

float GetValue(std::string str);

float GetValue(std::string str, float upper); 

float GetInterestRate(int crdSc); 

void Withdraw(float &amount, float withdrawAmount); 

int GetLoanMonths();

int GetCreditRating();

float CalculateLoanAmount(float principal, float intRate, int months);

void OutputAccount(float ammount);

