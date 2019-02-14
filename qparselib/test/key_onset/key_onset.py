from pynput import keyboard 
import time

total_time = time.time()
output = []
output.append(0)
output.append("\n")

def callb(key): #what to do on key-release
#     output.append(time.time()- total_time)
    output.append("\n")
    return False #stop detecting more key-releases
def callb1(key): #what to do on key-press
    output.append(time.time()- total_time)
    output.append(" ")
    return False #stop detecting more key-presse


try:
    while True:
        with keyboard.Listener(on_press = callb1) as listener1: #setting code for listening key-press
            listener1.join()
        with keyboard.Listener(on_release = callb) as listener: #setting code for listening key-release
            listener.join()
except KeyboardInterrupt:
    pass

output.pop() #delete the last element (one of the 2 escape character buttons)

for e in output:
    print(e, end = "")

with open('out.txt', 'w') as file_handler:
    for item in output:
        file_handler.write("{}".format(item))