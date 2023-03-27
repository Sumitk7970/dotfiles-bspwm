#!/bin/python

from ast import literal_eval
import datetime
import time
# import subprocess
# from colorama import Fore

# find the next_contest object 
next_contest = {}
with open("/home/sumit/.config/polybar/scripts/contests/upcoming_contests", "r") as f:
    for i,line in enumerate(f) :
        next_contest = literal_eval(line.strip("\n"))
        if next_contest["startTimeSeconds"] > int(time.time()) :
            break;

# contest_time in seconds
contest_time = next_contest["startTimeSeconds"]

# contest_time in datetime
contest_datetime = datetime.datetime.fromtimestamp(contest_time)

# current time in datetime
current_datetime = datetime.datetime.now()

# difference of days between contest_time and current_time
diff = contest_datetime.day - current_datetime.day

if diff > 1 :
    print(contest_datetime.strftime("%d/%m"))
elif diff == 1 :
    print("Kal " + contest_datetime.strftime("%-I:%M %p"))
elif diff == 0 :
    time_delta = contest_datetime - current_datetime
    # if time delta is less than 30 minutes then print output in red color
    time_delta_seconds = time_delta.total_seconds()
    if time_delta_seconds <= 30*60 :
        # print('%{F#ed8796}' + contest_datetime.strftime("%-I:%M %p") + "%{F-}")
        print('%{F#ed8796}' + str(int(time_delta_seconds/60)) + ' Mins' + '%{F-}')
    else :
        print(contest_datetime.strftime("%-I:%M %p"))
else :
    print("No contests data!!")

