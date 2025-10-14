#!/bin/bash

echo "***********************"
echo "                       "                   
echo "Welcome To signup page."
echo "                       "                   
echo "***********************"

echo "Please enter your name:"
read name

echo "Please enter your email address:"
read email

echo "Please enter your password:"
read password

echo "Please confirm your password:"
read confirm

if [ "$password" == "$confirm" ]; then
    echo "Your signup is successful!"
    echo "Name: $name"
    echo "Email: $email"
else
    echo "Passwords do not match! Please try again."
fi
