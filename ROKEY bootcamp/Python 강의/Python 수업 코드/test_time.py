import time_utils
import time

print("Current time:", time_utils.current_time()) # a
print("Sleeping for 2 seconds...")
start_time = time.time()
time_utils.sleep_for(2) # b
print("Current time:", time_utils.current_time()) # c
print("Elapsed time after sleeping:", time_utils.time_elapsed(start_time), "seconds")