import tkinter as tk

from tkinter import PhotoImage

problem20 = tk.Tk()
problem20.title("문제20)")
problem20.geometry("800x500")
label = tk.Label(problem20, text = "안녕하세요!")
label.pack(pady=20)
image = PhotoImage(file="/home/theo/Pictures/Screenshots/Screenshot from 2024-07-09 15-40-35.png")
image_label = tk.Label(problem20, image = image )
image_label.pack(pady=20)
button = tk.Button(problem20, text="버튼", command = lambda : print("버튼이 클릭되었습니다!"))
button.pack(pady=20)
problem20.mainloop()