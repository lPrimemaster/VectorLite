# VectorLite
VectorLite is a C++ tool to generate SVG's
This readme is a work in progress

# Features
|  **Features** |   **Implemented**  |
|:-------------:|:------------------:|
|  Draw Circles | :heavy_check_mark: |
|   Draw Quads  | :heavy_check_mark: |
| Draw Polygons |         :x:        |
|   CSS Styles  | :heavy_check_mark: |
| Custom Styles | :heavy_check_mark: |
|   Animations  |         :x:        |

# Usage
Example of usage
```Cpp
SVGWriter writer("test.svg");

SVGObject* c = new Circle(300, 300, 300, "c1");
SVGObject* q = new Quad(300, 300, 300 * 2 / sqrt(2), "p1");

SVGStyle style("circle.c1");
style["stroke"] = "red";
style["stroke-width"] = "5";
style["fill"] = "none";

SVGStyle style2("path.p1");
style2["stroke"] = "blue";
style2["stroke-width"] = "5";
style2["fill"] = "none";

writer.addStyle(style);
writer.addStyle(style2);

writer.storeObject(c);
writer.storeObject(q);

writer.write();
```

This generates the following SVG code
```SVG
<?xml version="1.0" encoding="utf-8"?>

<svg xmlns="http://www.w3.org/2000/svg"
xmlns:xlink="http://www.w3.org/1999/xlink" width="1280" height="720">
<defs><style type = "text/css"><![CDATA[
circle{ stroke: black; fill: none; }
path  { stroke: black; fill: none; }
circle.c1 {
stroke: red;
stroke-width: 5;
fill: none;
}
path.p1 {
stroke: blue;
stroke-width: 5;
fill: none;
}]]></style></defs>
<circle cx="300.000000" cy="300.000000" r="300.000000" class="c1"/>
<path d = "M87.867966 87.867966 		L512.132019 87.867966 		L512.132019 512.132019 		L87.867966 512.132019Z" class="p1"/>
</svg>
```

Which in turn displays the image that can be seen below

<img src="https://i.imgur.com/HHUTsTx.png" width="200" height="200" />
