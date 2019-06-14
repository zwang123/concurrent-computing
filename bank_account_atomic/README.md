# Bank Account

## Description

A banking system provides an illustration of basic threading concepts and the necessity of thread
synchronization. The system consists of a program running on a single central computer that controls
multiple automated teller machines (ATMs) in different locations. Each ATM has its own
thread so that the machines can be used simultaneously and easily share the bank’s account data.

The banking system has an Account class with a method to deposit and withdraw money from a
user’s account.

This is an alternative approach using atomic types

## Source

J. Mongan, N. S. Kindler, E. Giguere, in *Programming Interviews Exposed: Coding Your Way Through the Interview*, 4th Edition, John Wiley & Sons, Inc., Indiana, **2018**, p 168.
