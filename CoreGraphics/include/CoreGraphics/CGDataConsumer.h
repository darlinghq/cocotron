/* Copyright (c) 2009 Christopher J. W. Lloyd <cjwl@objc.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFURL.h>
#import <CoreGraphics/CoreGraphicsExport.h>

typedef struct CF_BRIDGED_TYPE(id) O2DataConsumer *CGDataConsumerRef;

CF_IMPLICIT_BRIDGING_ENABLED

typedef size_t (*CGDataConsumerPutBytesCallback)(void *info, const void *buffer, size_t count);

typedef void (*CGDataConsumerReleaseInfoCallback)(void *info);

typedef struct CGDataConsumerCallbacks {
    CGDataConsumerPutBytesCallback putBytes;
    CGDataConsumerReleaseInfoCallback releaseConsumer;
} CGDataConsumerCallbacks;

COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerCreateWithCFData(CFMutableDataRef data);
COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerCreate(void *info, const CGDataConsumerCallbacks *callbacks);
COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerCreateWithURL(CFURLRef url);

COREGRAPHICS_EXPORT void CGDataConsumerRelease(CGDataConsumerRef self);

CF_IMPLICIT_BRIDGING_DISABLED
