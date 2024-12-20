# HTML CANVAS

If you are planning to draw a lot of pixel,
it's a lot more efficient to use the image data of the canvas to do pixel drawing.

```javascript
var canvas = document.getElementById("myCanvas");
var canvasWidth = canvas.width;
var canvasHeight = canvas.height;
var ctx = canvas.getContext("2d");
var canvasData = ctx.getImageData(0, 0, canvasWidth, canvasHeight);

// That's how you define the value of a pixel
function drawPixel (x, y, r, g, b, a) {
    var index = (x + y * canvasWidth) * 4;
    canvasData.data[index + 0] = r;
    canvasData.data[index + 1] = g;
    canvasData.data[index + 2] = b;
    canvasData.data[index + 3] = a;
}

// That's how you update the canvas, so that your
// modification are taken in consideration
function updateCanvas() {
    ctx.putImageData(canvasData, 0, 0);
}

// Then, you can use it in this way :
drawPixel(1, 1, 255, 0, 0, 255);
drawPixel(1, 2, 255, 0, 0, 255);
drawPixel(1, 3, 255, 0, 0, 255);
updateCanvas();
```

For more information, you can take a look at this Mozilla blog post :

http://hacks.mozilla.org/2009/06/pushing-pixels-with-canvas/


