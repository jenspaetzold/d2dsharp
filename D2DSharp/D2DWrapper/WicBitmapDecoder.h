/* 
* 
* Authors: 
*  Dmitry Kolchev <dmitrykolchev@msn.com>
*  
*/
#pragma once

#include "WicBitmapFrameDecode.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace Managed { namespace Graphics { namespace Imaging
{
	public ref class WicBitmapDecoder: ComWrapper
	{
	internal:
		WicBitmapDecoder(IWICBitmapDecoder* native): ComWrapper(native)
		{
		}
	public:
		property int FrameCount
		{
			int get()
			{
				UINT count;
				ComUtils::CheckResult(GetNative<IWICBitmapDecoder>()->GetFrameCount(&count));
				return (int)count;
			}
		}

		WicBitmapFrameDecode^ GetFrame(int index)
		{
			IWICBitmapFrameDecode* frame;
			ComUtils::CheckResult(GetNative<IWICBitmapDecoder>()->GetFrame((UINT) index, &frame));
			return gcnew WicBitmapFrameDecode(frame);
		}
	};
}}}