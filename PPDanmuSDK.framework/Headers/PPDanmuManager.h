//
//  PPDanmuManager.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/22.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DanmuAddBean,PPYError,DanmuListBean;
@interface PPDanmuManager : NSObject

@property (nonatomic, strong, nonnull) NSString *token;
@property (nonatomic, strong, nonnull) NSString *userName;
/**
 平台，支持pplive，可配置加入新的平台；暂时支持pplive, live, sport, aibo, wan1717, concept, tribe, partner
 */
@property (nonatomic, strong, nonnull) NSString *platform;

/**
 *  初始化方法
 *  (token必须要和userName对应)
 */
- (nonnull instancetype)initWithToken:(nonnull NSString *)token
                             userName:(nonnull NSString *)userName
                             platform:(nonnull NSString *)platform;

//发布弹幕
- (void)publishDanmu:(nonnull DanmuAddBean *)danmu completion:(void (^_Nullable)(PPYError * _Nullable error))completion;


/**
 获取视频弹幕列表

 @param channelID 视频ID
 @param position 时间单位(0.1秒)，传 0 表示从头开始，第二次请求传上一次返回的 end 值
 @param completion block回调，成功 返回弹幕列表，失败 返回错误信息
 */
- (void)getDanmuListWithChannelID:(nonnull NSString *)channelID position:(long)position completion:(void (^_Nullable)(DanmuListBean *_Nullable list, PPYError * _Nullable error))completion;
@end
