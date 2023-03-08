#!/bin/python

from ast import literal_eval
from datetime import datetime
import time

current_time = datetime.now()

next_contest = {}
with open("/home/sumit/.config/polybar/modules/contests/upcoming_contests", "r") as f:
    for i,line in enumerate(f) :
        next_contest = literal_eval(line.strip("\n"))
        if next_contest["startTimeSeconds"] > int(time.time()) :
            break;

# contest_time in seconds
contest_time = next_contest["startTimeSeconds"]

# contest_time in datetime
contest_time_dt = datetime.fromtimestamp(contest_time)

delta = contest_time_dt - current_time

if delta.days > 1 :
    print(contest_time_dt.strftime("%d/%m"))
elif delta.days == 1 :
        print("Kal " + contest_time_dt.strftime("%-I:%M %p"))
else :
    print(contest_time_dt.strftime("%-I:%M %p"))
