import time

def current_time():
    t = time.localtime()
    return  time.strftime("%Y-%m-%d %H:%M:%S", t)

def sleep_for(s):
    time.sleep(s)
    
def time_elapsed(start_time):
    return time.time() - start_time

if __name__ == "__main__":
    print(current_time())
    start_time = time.time()
    sleep_for(2)
    print(time_elapsed(start_time))
    