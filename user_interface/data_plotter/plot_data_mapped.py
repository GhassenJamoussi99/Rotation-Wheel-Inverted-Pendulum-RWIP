import re
import math
import plotly.graph_objects as go

# Path to your text file
file_path = 'test2.txt'

# Initialize an empty list to store the numbers
angles = []

# Open the file and read line by line
with open(file_path, 'r') as file:
    for line in file:
        # Find all numbers in the line
        found_numbers = re.findall(r"[-+]?\d*\.\d+|\d+", line)
        # Extend the numbers list with found numbers
        angles.extend([float(num) for num in found_numbers])

# Time interval in milliseconds 
time_interval = 76
current_time = 0
time = []

# Adjusting the time vector to reflect ms intervals
#time = [i * time_interval / 1000.0 for i in range(len(angles))]

for i in range(len(angles)):
    if (angles[i] == 153.143936):
        time_interval = 21
    current_time += time_interval / 1000.0
    time.append(current_time)


def map_angle(angle):
    if angle > 210:
        return angle - 360
    else:
        return angle

angles = [map_angle(angle) for angle in angles] #mapped
print(angles)

angles = [math.radians(angle) for angle in angles] #in rad
print(angles)


print("time_vector =",time)

# Plotting the data using Plotly
fig = go.Figure(data=go.Scatter(x=time, y=angles, mode='lines'))
fig.update_layout(title='Pendulum angle over Time',
                  xaxis_title='Time (Seconds)',
                  yaxis_title='Angle (Radians)',
                  template='plotly_white')
fig.show()
