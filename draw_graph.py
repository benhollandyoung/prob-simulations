import matplotlib.pyplot as plt
import networkx as nx

G = nx.read_edgelist("graph_edges.txt", nodetype=int)

plt.figure(figsize=(8, 6))
nx.draw(G, with_labels=True, node_color="skyblue", edge_color="gray", node_size=600)
plt.title("Erdos-Renyi Graph")
plt.show()