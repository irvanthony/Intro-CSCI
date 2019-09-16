# Irvin A. Carbajal
# Assignment 9
# Recitation:
# Instructor: Stephen Hutt

#!/usr/bin/env python

#this function took in a list and an integer as a parameter to calculate the population in the USA in one year.
#Each of the rates are either index 0, 1 , or 2 of the list int the order ot birth, death, and immigrant rate
#It adds/subtracts depending on the sign of the rate (birth is a plus and death in a negative)
def compute_census(list_of_rates, curr_population): 
    #list_of_rates = [birth_rate, death_rate, new_immigrant_rate]
    birth_rate = list_of_rates[0]
    death_rate = list_of_rates[1]
    new_immigrant_rate = list_of_rates[2]
    secs_year = 31536000
    a = secs_year / birth_rate
    b = secs_year / death_rate
    c = secs_year / new_immigrant_rate

    pop = curr_population + a - b + c
    
    return pop
   
#This convers seconds into days, hours, minutes and seconds and prints it in a string
#The function doesnt use loops or anything but the division/modulo operation.
def convert_seconds():
    x = input()
    time = x
    days = x / 86400
    x %= 86400
    hours = x / 3600
    x %= 3600
    minutes = x / 60
    seconds = x % 60
    print "%d corresponds to: %d days, %d hours, %d minutes, %d seconds." % (time, days, hours, minutes, seconds)
	
	
#This function takes in a list as a parameter.
#It works by using the index of the strings in the list.
def generate_story(list_to_story):
	y = raw_input(list_to_story[1] + ': ')
	z = input(list_to_story[3] + ': ')
	return list_to_story[0] + ' ' + y + ' ' + list_to_story[2] + ' ' + str(z) + ' ' + list_to_story[4]
 
#This function takes in two parameters and compares them to calculate a similarity.
#Uses if statements and a for loop.
def similarity_score(seq1, seq2):
    mismatches = 0.0
    if (len(seq1) != len(seq2)):
		return 0.0
    for i in range (len(seq1)):
        if (seq1[i] != seq2[i]):
            mismatches += 1
    return (len(seq1) - mismatches) / len(seq1)
	
def best_match(genome, seq):
    bestMatch = 0
    i = 0
    while (i+(len(seq))) <= (len(genome)):
        if similarity_score(genome[i:i+(len(seq))], seq) < bestMatch:
            bestMatch = bestMatch
        else:
            bestMatch = similarity_score(genome[i:i+(len(seq))], seq)
        i = i + 1
	return bestMatch
	
def calc_stats(list_of_numbers):
    final_list=[]
    total = 0.0
    length = 0
    for i in list_of_numbers:
        total += i
        length +=1
    if(length!=0):
        avg = total / length
        final_list.append(avg)
    else:
        final_list.append(None)
    list_of_numbers.sort()
    a = float(len(list_of_numbers))
    if a % 2 == 0:
        b = float(list_of_numbers[len(list_of_numbers)/2])
        c = float(list_of_numbers[(len(list_of_numbers)/2)-1])
        d = (b + c) / 2.0
        final_list.append(d)

    if a % 2 > 0:
		e=float(list_of_numbers[len(list_of_numbers)/2])
		final_list.append(e)
    return final_list

def parse_ratings(file_name):
    f=open(file_name)
    rating=[]
    for line in f:
        line=line.strip()
        sep=line.split(',')
        sname=sep[0]
        ratings=sep[1].split()
        lists=[]
        lists.append(sname)
        lists2=[]
        for i in ratings:
            lists2.append(int(i))
        lists.append(lists2)
        rating.append(lists)
    return rating
		
	
	

def main():
    #Each function is tested by providing a sample of the parameter type required.
    #A list was created as an example
    lists = [8, 12, 33]
    compute_census(lists, 1000000)
    
    convert_seconds()
    seq1 = "CCGCCGCCGA"
    seq2 = "CCTCCTCCTA"
    similarity_score(seq1, seq2)
    best_match(seq1, seq2)
    calc_stats(lists)
    parse_ratings()
    
if __name__ == '__main__':
	main()
