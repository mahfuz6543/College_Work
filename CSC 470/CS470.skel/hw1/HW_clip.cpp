#include "IP.h"
using namespace IP;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW_clip:
//
// Clip intensities of image I1 to [t1,t2] range. Output is in I2.
// If    input<t1: output = t1;
// If t1<input<t2: output = input;
// If      val>t2: output = t2;
//
void
HW_clip(ImagePtr I1, int t1, int t2, ImagePtr I2)
{

// PUT YOUR CODE HERE
	IP_copyImageHeader(I1, I2);

	// init vars for width, height, and total number of pixels
	int w = I1->width();
	int h = I1->height();
	int total = w * h;

	// init lookup table
	// any pixel values less than t1 will be clipped to t1
	// any pixel values between t1 and t2 will stay the same
	// any pixel values greater than t2 will be clipped to t2
	int i, lut[MXGRAY];
	for (i = 0; i < MXGRAY; ++i) {
		if (i < t1) lut[i] = t1;
		else if (i > t2) lut[i] = t2;
		else lut[i] = i;
	}

	// declarations for image channel pointers and datatype
	ChannelPtr<uchar> p1, p2;
	int type;

	// Note: IP_getChannel(I, ch, p1, type) gets pointer p1 of channel ch in image I.
	// The pixel datatype (e.g., uchar, short, ...) of that channel is returned in type.
	// It is ignored here since we assume that our input images consist exclusively of uchars.
	// IP_getChannel() returns 1 when channel ch exists, 0 otherwise.

	// visit all image channels and evaluate output image
	for (int ch = 0; IP_getChannel(I1, ch, p1, type); ch++) {	// get input  pointer for channel ch
		IP_getChannel(I2, ch, p2, type);		// get output pointer for channel ch
		for (i = 0; i < total; i++) *p2++ = lut[*p1++];	// use lut[] to eval output
	}

}
