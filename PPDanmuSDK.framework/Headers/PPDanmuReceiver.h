//
//  PPDanmuReceiver.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/17.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PPReceiverConnectState) {
    PPReceiverConnectStateOK                       = 0,
    PPReceiverConnectStateUnacceptProtocolVersion  = 1,
    PPReceiverConnectStateNotAuthorized            = 2,
    PPReceiverConnectServerUnavailable        = 3,
    PPReceiverConnectClientIDOccupied         = 4,
    PPReceiverConnectServerBusy               = 5,
};

typedef NS_ENUM(NSUInteger, PPReceiverState) {
    PPReceiverStateInitialized,
    PPReceiverStateLogined,
    PPReceiverStateLoginFailure,
    PPReceiverStateConnectionLost,
    PPReceiverStateStateStopped,
};

@class PPDanmuReceiver,PPMessage,DanmuList;
@protocol PPDanmuReceiverDelegate <NSObject>
@optional
/**
 *  连接结果回调
 */
- (void)receiver:(nonnull PPDanmuReceiver *)receiver connectState:(PPReceiverConnectState)state;
/**
 *    收到消息回调
 */
- (void)receiver:(nonnull PPDanmuReceiver *)receiver receiveDanmu:(nonnull DanmuList *)danmu;
/**
 *   连接断开回调
 */
- (void)receiverDidLostConnection:(nonnull PPDanmuReceiver *)receiver;
@end

/** 弹幕接受 */
@interface PPDanmuReceiver : NSObject

@property (nonatomic, assign, readonly) PPReceiverState receiverState;
@property (nonatomic, strong, nonnull) NSString *appID;
@property (nonatomic, strong, nonnull) NSString *appKey;

/** 初始化 */
- (nonnull instancetype)initWithAppID:(nonnull NSString *)appID
                               appKey:(nonnull NSString *)appKey;

@property (nullable, nonatomic, weak) id <PPDanmuReceiverDelegate> delegate;

/**
 *  开始接受弹幕消息
 */
- (void)start;

/**
 *  停止接受弹幕消息
 */
- (void)stop;

/**
 *  添加监听的Tag
 *
 *  @param tag               tag
 */
- (void)addTag:(nonnull NSString *)tag;

/**
 *  移除Tag
 *
 *  @param tag tag
 */
- (void)removeTag:(nonnull NSString *)tag;

/**
 *  移除所有已添加的tag
 */
- (void)clearTags;

/**
 *  重新连接服务器
 */
- (void)reconnect;

@end
