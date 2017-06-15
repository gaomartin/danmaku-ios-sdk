# PP云弹幕SDK使用说明（IOS）
## 一. 功能特点
-  [收弹幕]：通过长连接接收实时弹幕
-  [发弹幕]：通过短连接发送弹幕

## 二. 运行环境
最低支持版本为IOS8.0

支持的CPU架构：armv7,arm64
## 三. 快速集成

配置工程文件：
在工程文件->General->Embedded Binaries 项中导入动态库：PPDanmuSDK

引入头文件： #import \<PPDanmuSDK/PPDanmuSDK.h>

## 接口说明：
### 1. PPDanmuManager 发送弹幕
初始化

```objc
PPDanmuManager *danmu = [[PPDanmuManager alloc] initWithToken:TestToken
                                                     userName:TestUserName
                                                     platform:@"pplive"];
                                                
//创建弹幕对象

  DanmuAddBean *bean = [[DanmuAddBean alloc] initWithChannelId:channelID
                                                       content:message
                                                     playPoint:120
                                                     fontColor:@"#11FFFF"
                                                      fontName:@"字体名称"
                                                      fontSize:PPDanmuFontSizeBig
                                                  fontPosition:PPDanmuFontPositionTopCenter 
                                                        motion:PPDanmuFontMotionNatant];
    [danmu publishDanmu:bean
             completion:^(PPYError * _Nullable error) {
                      if (error == nil) {
                          NSLog(@"发表成功");
                      } else {
                          NSLog(@"发布失败:%@",error.message);
                      }
                  }];
```

### 2. PPDanmuReceiver 接受弹幕
初始化

```objc
PPDanmuReceiver *receiver = [[PPDanmuReceiver alloc] initWithAppID:@"xxxxxx"
                                                            appKey:@"xxxxxxxxx"];
receiver.delegate = self;
[receiver addTag:@"danmu/live_300403"]; //添加需要接受弹幕的tag
[receiver addTag:@"danmu/vod_25992089"];
[receiver start]; //开始连接，接受弹幕
    

接受弹幕回调
/**
 *  连接结果回调
 */
- (void)receiver:(nonnull PPDanmuReceiver *)receiver connectState:(PPReceiverConnectState)state;
/**
 *    收到消息回调
 */
- (void)receiver:(nonnull PPDanmuReceiver *)receiver receiveDanmu:(nonnull DanmuMessageList *)danmu;
/**
 *   连接断开回调
 */
- (void)receiverDidLostConnection:(nonnull PPDanmuReceiver *)receiver;
```

### 3.获取视频弹幕列表
初始化

```objc
PPDanmuManager *danmu = [[PPDanmuManager alloc] initWithToken:token
                                                     userName:name
                                                     platform:@"pplive"];
 [danmu getDanmuListWithChannelID:self.channelID
                         position:lastEndPos
                       completion:^(DanmuListBean * _Nullable list, PPYError * _Nullable error) {
                                          if (list) {
                                             //list.infos  弹幕列表  
                                          }
                                      }];
```
关于position的说明，第一次请求直播弹幕，传入参数 position =视频播放的自然时间(当前视频播放进度返回,0就表示从头开始)。后台返回（自然时间-10s）到（自然时间）的弹幕，并告诉end和ts=10s。 
前端根据上一次请求的时间，在ts之后做第二次请求，传入position={end}。sdk返回（position）到(position+10s)的弹幕，并告诉新的end和ts
position 的单位为 0.1秒

### 4.设置弹幕视图
```objc
//设置弹幕需要显示的视图
[danmuManager setRendererView:self.videoView];

//准备开始接受弹幕
[danmuManager startDanmu];

//接受弹幕并显示出来
[danmuManager rendererDanmu:danmu];

//暂停弹幕
[danmuManager startDanmu];

//停止弹幕
[danmuManager startDanmu];


//如果是点播弹幕，先拉取弹幕列表，然后显示弹幕

//点播弹幕需要实现代理方法，sdk会自动根据播放时间不断显示对应的弹幕
danmuManager.rendererDelegate = self;

//返回当前播放器的播放时间(秒)
- (NSTimeInterval)currentPlayTimeForManager:(PPDanmuManager *)manager {
    return self.playTime / 10;
}
//弹幕显示模式，可以设置显示全屏，半屏
@property (nonatomic, assign) PPDanmuDisplayMode displayMode;
```