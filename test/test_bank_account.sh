#!/bin/bash
make bank_account.out
for i in {0..100}; do test "`./bank_account.out 234`" != '234' && echo error; done
make bank_account_atomic.out
for i in {0..100}; do test "`./bank_account_atomic.out 234`" != '234' && echo error; done
