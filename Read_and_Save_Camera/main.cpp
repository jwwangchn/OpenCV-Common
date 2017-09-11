#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture usbCamera(1);//读取usb摄像头视频
	VideoCapture flirCamera(0);
	if(!usbCamera.isOpened() || !flirCamera.isOpened())
	{
		cout<<"Capture could not be opened successfully"<<endl;
		return -1;
	}

	Size usbSize=Size((int)usbCamera.get(CV_CAP_PROP_FRAME_WIDTH),(int)usbCamera.get(CV_CAP_PROP_FRAME_HEIGHT));
	Size flirSize = Size((int)flirCamera.get(CV_CAP_PROP_FRAME_WIDTH),(int)flirCamera.get(CV_CAP_PROP_FRAME_HEIGHT));
	VideoWriter usbWriter("../USBCamera.avi",CV_FOURCC('M','J','P','G'),25.0,usbSize);//输出保存为视频名为output.mpg；MPEG为对应的编码器。
    VideoWriter flirWriter("../flirCamera.avi",CV_FOURCC('M','J','P','G'),25.0,flirSize);//输出保存为视频名为output.mpg；MPEG为对应的编码器。
	//VideoWriter put("output.avi",CV_FOURCC('M','P','E','G'),50,S);//可以将视频保存为avi格式的
	if(!usbWriter.isOpened() || !flirWriter.isOpened())
	{
		cout<<"File could not be created for writing. Check permissions"<<endl;
		return -1;
	}
	namedWindow("USB");
	namedWindow("Flir");
	while(char(waitKey(1))!='q' && usbWriter.isOpened() && flirWriter.isOpened())
	{
		Mat usbFrame, flirFrame;
		usbCamera >> usbFrame;
		flirCamera >> flirFrame;
		if(usbFrame.empty() || flirFrame.empty())
		{
			cout<<"Video over"<<endl;
			break;
		}
		imshow("USB",usbFrame);
		imshow("Flir",flirFrame);
		usbWriter << usbFrame;
		flirWriter << flirFrame;
	}
	return 0;
}
