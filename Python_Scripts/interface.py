import tkinter as tk
from gcode import generate_preview, generate_file, check_filename

class InstructionGeneratorApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Instructions Generator")
        self.root.geometry("300x225")
        self.root.resizable(False, False)

        # Configure grid
        self.root.grid_columnconfigure(0, weight=1)

        # --- Widgets ---
        self.title = tk.Label(
            root,
            text="CNC Writing Machine Instructions Generator",
            font=("Helvetica", 10, "bold")
        )

        self.first_instruction = tk.Label(
            root,
            text="Insert Gcode instructions file name:"
        )

        self.entry_name = tk.Entry(root, width=30)

        self.preview_var = tk.IntVar()
        self.preview_checkbox = tk.Checkbutton(
            root, text="Show preview", variable=self.preview_var
        )

        self.files_var = tk.IntVar()
        self.files_checkbox = tk.Checkbutton(
            root, text="Generate instruction files", variable=self.files_var
        )

        self.warning = tk.Label(root, text="", fg="red")

        self.generate_button = tk.Button(
            root, text="Generate", command=self.generate
        )

        # --- Layout ---
        self.title.grid(row=0, column=0, pady=10)
        self.first_instruction.grid(row=2, column=0, pady=5)
        self.entry_name.grid(row=3, column=0)
        self.preview_checkbox.grid(row=5, column=0, padx=70, sticky="w")
        self.files_checkbox.grid(row=6, column=0, padx=70, sticky="w")
        self.warning.grid(row=7, column=0)
        self.generate_button.grid(row=8, column=0, pady=10)

    def generate(self):
        preview = self.preview_var.get()
        files = self.files_var.get()
        filename = self.entry_name.get()

        if preview == 0 and files == 0:
            self.warning.config(text="Select an option")

        elif not check_filename(filename):
            self.warning.config(text="File doesn't exist")

        else:
            if preview and not files:
                self.root.destroy()
                generate_preview(filename)
            elif files and not preview:
                self.root.destroy()
                generate_file(filename)
            else:
                self.root.destroy()
                generate_file(filename)
                generate_preview(filename)


# --- Main Execution ---
if __name__ == "__main__":
    root = tk.Tk()
    app = InstructionGeneratorApp(root)
    root.mainloop()
