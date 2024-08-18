import re
import plotly.graph_objects as go

# Path to your text file
file_path = 'test4_kraft.txt'

# Initialize an empty list to store the numbers
angles = []

# Open the file and read line by line
with open(file_path, 'r') as file:
    for line in file:
        # Find all numbers in the line
        found_numbers = re.findall(r"[-+]?\d*\.\d+|\d+", line)
        # Extend the numbers list with found numbers
        angles.extend([float(num) for num in found_numbers])

# Time interval in milliseconds (160 ms)
time_interval = 20

# Adjusting the time vector to reflect 160 ms intervals
time = [i * time_interval / 1000.0 for i in range(len(angles))]

def map_angle(angle):
    if angle > 180:
        return angle - 360
    elif angle <= -180:
        return angle + 360
    else:
        return angle
    
print(angles)

# Plotting the data using Plotly
fig = go.Figure(data=go.Scatter(x=time, y=angles, mode='lines'))
fig.update_layout(title='Pendulum angle over Time',
                  xaxis_title='Time (Seconds)',
                  yaxis_title='Angle (Degrees)',
                  template='plotly_white')
fig.show()
