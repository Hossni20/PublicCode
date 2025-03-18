import tkinter as tk
from time import strftime
from PIL import Image, ImageTk

class DesktopClock:
    def __init__(self, root):
        self.root = root
        self.root.overrideredirect(True)  # Remove window decorations
        self.root.attributes("-topmost", True)  # Always on top
        self.root.attributes("-transparentcolor", "black")  # Make black transparent
        
        self.frame = tk.Frame(root, bg="black")
        self.frame.pack()
        
        self.label = tk.Label(self.frame, font=("Arial", 40, "bold"), fg="white", bg="black")
        self.label.pack()
        
        self.update_time()
        self.make_draggable()

    def update_time(self):
        self.label.config(text=strftime('%H:%M:%S'))
        self.root.after(1000, self.update_time)

    def make_draggable(self):
        self.label.bind("<ButtonPress-1>", self.start_move)
        self.label.bind("<B1-Motion>", self.do_move)

    def start_move(self, event):
        self.x = event.x
        self.y = event.y

    def do_move(self, event):
        x = self.root.winfo_x() + event.x - self.x
        y = self.root.winfo_y() + event.y - self.y
        self.root.geometry(f"+{x}+{y}")

if __name__ == "__main__":
    root = tk.Tk()
    DesktopClock(root)
    root.mainloop()
