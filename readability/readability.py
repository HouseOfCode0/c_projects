from sys import argv, exit
from cs50 import get_string


text = get_string("Text: ")

letter = 0
word = 1
sentence = 0

for i in range (len(text)):
    if text[i].isalpha():
        letter = letter + 1

    if text[i] == " " and text[i+1] != " " :
         word = word + 1

    if text[i] == "." or  text[i] == "?" or  text[i] == "!":
        sentence = sentence +1


L =(letter/word)*100
S = (sentence/word) *100

index = round(0.0588 * L - 0.296 * S - 15.8);


if index < 1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

elif index == 10:
    print("Grade X")

else:
    print(f"Grade {index}");
