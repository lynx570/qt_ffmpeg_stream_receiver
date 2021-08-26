#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QImage>
#include "global.h"

extern "C"
{
#include "libavformat/avformat.h"
#include "libavutil/mathematics.h"
#include "libavutil/time.h"
#include "libavcodec/avcodec.h"
#include <libavutil/opt.h>
#include <libavutil/imgutils.h>
#include "libavformat/avio.h"
#include "libswscale/swscale.h"
}

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    void get_stream();
    void get_images_from_streem();
    std::string rtpUrl;

private:


signals:
    void sig_new_frame(QImage);

};

#endif // WORKER_H
