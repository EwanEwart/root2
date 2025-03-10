# Draw(chopt)
E.g.:  
graph->Draw("ALPX+Y+");  

refer to class TGraphPainter : https://root.cern/doc/master/classTGraphPainter.html

|------------------------------------------------------------------------------------------|
|chopt   |   Description
|------------------------------------------------------------------------------------------|
|"A" 	 |   Produce a new plot with Axis around the graph
|"I" 	 |   Combine with option 'A' it draws invisible axis
|"L" 	 |   A simple polyline is drawn
|"F" 	 |   A fill area is drawn ('CF' draw a smoothed fill area)
|"C" 	 |   A smooth Curve is drawn
|"*" 	 |   A Star is plotted at each point
|"P" 	 |   The current marker is plotted at each point
|"B" 	 |   A Bar chart is drawn
|"1" 	 |   When a graph is drawn as a bar chart, 
|        |    this option makes the bars start from the bottom of the pad. 
|        |    By default they start at 0.
|"X+" 	 |   The X-axis is drawn on the top side of the plot.
|"Y+" 	 |   The Y-axis is drawn on the right side of the plot.
|"PFC" 	 |   Palette Fill Color: graph's fill color is taken in the current palette.
|"PLC" 	 |   Palette Line Color: graph's line color is taken in the current palette.
|"PMC" 	 |   Palette Marker Color: graph's marker color is taken in the current palette.
|"RX" 	 |   Reverse the X axis.
|"RY" 	 |   Reverse the Y axis.
|------------------------------------------------------------------------------------------|
