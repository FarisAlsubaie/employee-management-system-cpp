from tkinter import *

root = Tk()
root.title("Counter App")
root.geometry("450*300")

count = 0

def increase():
    global count
    count += 1
    label.config(text=count)

def decrease():
    global count
    count -= 1
    label.config(text=count)

label = Label(root, text=count, font=("Arial", 30))
label.pack(pady=20)

btn1 = Button(root, text="+", font=("Arial", 20), command=increase)
btn1.pack(side=LEFT, padx=40)

btn2 = Button(root, text="-", font=("Arial", 20), command=decrease)
btn2.pack(side=RIGHT, padx=40)

root.mainloop()