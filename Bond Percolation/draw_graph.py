import matplotlib.pyplot as plt

# Load edges
edges = []
with open("edges.csv", "r") as f:
    for line in f:
        x1, y1, x2, y2 = map(int, line.strip().split(','))
        edges.append(((x1, y1), (x2, y2)))

# Plotting
fig, ax = plt.subplots()
for (x1, y1), (x2, y2) in edges:
    ax.plot([x1, x2], [y1, y2], 'k-')  # black lines

# Optional: add grid points
points = set(p for edge in edges for p in edge)
for (x, y) in points:
    ax.plot(x, y, 'ro', markersize=2)

ax.set_aspect('equal')
plt.title("Percolation Graph")
plt.grid(True)
plt.show()