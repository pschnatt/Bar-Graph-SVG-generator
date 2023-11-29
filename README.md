# Bar Graph SVG Generator

This C++ program generates a simple bar graph in SVG format based on input data. The program reads data from a file, creates a bar graph, and saves it as an SVG file.

## How to Use

### 1. Input Data

Prepare a text file ("text.txt" in this example) containing data in the format of "Name Value" pairs, where each line represents a data point. For example:
```
Apple 20
Banana 35
Orange 15
```

### 2. Compile and Run

Compile the C++ program using a C++ compiler, such as g++. Run the compiled executable, and it will generate an SVG file named "graph.svg" with the specified bar graph.

```bash
g++ miniproj.cpp -o graph_generator
./graph_generator
```

### 3. View the Bar Graph

Open the generated SVG file ("graph.svg") using a web browser or any SVG viewer to visualize the bar graph.

## Customization

You can customize the appearance of the generated bar graph by modifying the code. The following parameters can be adjusted in the `generate` function of the `BarGraphGenerator` class:

- `bargraph_name`: Name/title of the bar graph.
- `values`: Vector containing the numerical values for each bar.
- `labels`: Vector containing labels for each bar.
- `color`: Color of the bars in the graph.

## Dependencies

The program uses C++ standard libraries and does not have external dependencies.

## File Structure

- `your_code.cpp`: The main C++ source code file.
- `text.txt`: Example input file with data.
- `graph.svg`: The generated SVG file.

## Notes

- Ensure that the input file ("text.txt") follows the specified format (Name Value).
- The program currently assumes each line in the input file contains only two elements.
- The generated SVG file may need a compatible viewer for proper visualization.

Feel free to modify and enhance the code to suit your specific requirements!
