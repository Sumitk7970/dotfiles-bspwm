#!/bin/python

import requests 
import datetime

current_time = int(datetime.datetime.now().timestamp())

response = requests.get("https://codeforces.com/api/contest.list?gym=false")

contests = response.json()["result"]

# filter upcoming_contests
upcoming_contests = []
for contest in contests :
    if contest["phase"] == "BEFORE" and contest["startTimeSeconds"] > current_time : 
        upcoming_contests.append(contest)

# sorting the upcoming_contests according to start time
upcoming_contests.sort(key=lambda contest: contest["startTimeSeconds"])

# print upcoming_contests to file
with open('upcoming_contests', 'w') as f:
    for contest in upcoming_contests : 
        print(contest, file=f)
