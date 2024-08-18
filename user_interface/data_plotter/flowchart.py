import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle, FancyBboxPatch, Arrow

# Define a function to draw an arrow
def draw_arrow(ax, start, end):
    arrow = Arrow(start[0], start[1], end[0]-start[0], end[1]-start[1], width=0.1, color='black')
    ax.add_patch(arrow)

# Define a function to draw a process box
def draw_process(ax, center, text):
    box = FancyBboxPatch((center[0]-1, center[1]-0.3), 2, 0.6, boxstyle="round,pad=0.1", ec="black", fc="white")
    ax.add_patch(box)
    ax.text(center[0], center[1], text, ha='center', va='center')

# Define a function to draw a decision diamond
def draw_decision(ax, center, text):
    diamond = FancyBboxPatch((center[0]-0.7, center[1]-0.7), 1.4, 1.4, boxstyle="diamond,pad=0.1", ec="black", fc="white")
    ax.add_patch(diamond)
    ax.text(center[0], center[1], text, ha='center', va='center')

# Define a function to draw a start/end ellipse
def draw_start_end(ax, center, text):
    ellipse = FancyBboxPatch((center[0]-0.9, center[1]-0.3), 1.8, 0.6, boxstyle="round,pad=0.1", ec="black", fc="white")
    ax.add_patch(ellipse)
    ax.text(center[0], center[1], text, ha='center', va='center')

# Initialize the plot
fig, ax = plt.subplots(figsize=(10, 15))
ax.set_xlim(0, 10)
ax.set_ylim(0, 17)
ax.axis('off')

# Draw the start point
draw_start_end(ax, (5, 16), "Start")

# Draw the processes
draw_process(ax, (5, 14.5), "Scan student card\nwith RFID reader")
draw_process(ax, (5, 12.5), "Store student RFID data\nin central database")
draw_process(ax, (5, 10.5), "Generate QR code\nfor device borrowing")
draw_process(ax, (5, 8.5), "Student scans QR code\nto request device")
draw_process(ax, (5, 6.5), "Verify device availability")
draw_process(ax, (5, 4.5), "Assign available device to\nstudent & update database")

# Draw the decision diamond
draw_decision(ax, (5, 2.5), "Device borrowed?")

# Draw the end point
draw_start_end(ax, (5, 0.5), "End")

# Draw arrows
draw_arrow(ax, (5, 15.7), (5, 15))
draw_arrow(ax, (5, 14), (5, 13))
draw_arrow(ax, (5, 12), (5, 11))
draw_arrow(ax, (5, 10), (5, 9))
draw_arrow(ax, (5, 8), (5, 7))
draw_arrow(ax, (5, 6), (5, 5))
draw_arrow(ax, (5, 4), (5, 3))

# Draw arrows for decision outcomes
draw_arrow(ax, (5, 2), (5, 1))

# Show the plot
plt.show()
