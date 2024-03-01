from graphviz import Digraph

dot = Digraph(comment="Project Structure")
dot.attr(rankdir="LR")

# Add nodes for directories
dot.node("A", "Project Root")
dot.node("B", "src")
dot.node("C", "reports")

# Add nodes for file groups
dot.node("D", ".c Files")
dot.node("E", ".h Files")
dot.node("F", ".life Files")
dot.node("G", "Makefile")

# Add nodes for individual files
dot.node("H", "main.c")
dot.node("I", "prepare_space.c")
dot.node("J", "update_space.c")
dot.node("K", "count_friends.c")
dot.node("L", "life_cycle.c")
dot.node("M", "load_save.c")
dot.node("N", "print_png.c")
dot.node("O", "print_space.c")
dot.node("P", "toys.c")
dot.node("Q", "service.h")
dot.node("R", "example.life")
dot.node("S", "gliders.life")

# Add edges to show relationships
dot.edges(["AB", "AC"])  # Root directory relationships
dot.edges(["BD", "BE", "BF", "BG"])  # src directory relationships
dot.edges(["DH", "DI", "DJ", "DK", "DL", "DM", "DN", "DO", "DP"])  # .c files
dot.edges(["EQ"])  # .h files
dot.edges(["FR", "FS"])  # .life files

# Save the graph to a file
dot.render("project_structure_grouped.gv", view=True)
