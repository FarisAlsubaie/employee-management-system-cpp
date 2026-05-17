from tkinter import *

# window
root = Tk()
root.title("Calculator")
root.geometry("300x400")

# input screen
entry = Entry(root, width=20, font=("Arial", 20))
entry.pack(pady=20)

# function
def click(number):
    current = entry.get()
    entry.delete(0, END)
    entry.insert(0, current + str(number))

# clear screen
def clear():
    entry.delete(0, END)

# equal
def equal():
    result = eval(entry.get())
    entry.delete(0, END)
    entry.insert(0, str(result))

# buttons
Button(root, text="1", width=5, height=2,
       command=lambda: click(1)).pack()

Button(root, text="2", width=5, height=2,
       command=lambda: click(2)).pack()

Button(root, text="3", width=5, height=2,
       command=lambda: click(3)).pack()

Button(root, text="4", width=5, height=2,
       command=lambda: click(4)).pack()


Button(root, text="+", width=5, height=2,
       command=lambda: click("+")).pack()

Button(root, text="=", width=5, height=2,
       command=equal).pack()

Button(root, text="Clear", width=5, height=2,
       command=clear).pack()

# run app
root.mainloop()