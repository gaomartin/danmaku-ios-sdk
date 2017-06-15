//
//  PPDanmuManager.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/22.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PPDanmuEnum.h"

@class DanmuAddBean,PPYError,DanmuListBean,DanmuContent,PPDanmuManager;

@protocol PPDanmuRendererDelegate <NSObject>
@optional
- (NSTimeInterval)currentPlayTimeForManager:(PPDanmuManager *_Nonnull)manager;
@end

@interface PPDanmuManager : NSObject
/**
 初始化方法
 (token必须要和userName对应)

 @param token 用户token
 @param userName 和token对应的用户名
 @param platform 平台，支持pplive，可配置加入新的平台；暂时支持pplive, live, sport, aibo, wan1717, concept, tribe, partner
 */
- (nonnull instancetype)initWithToken:(nonnull NSString *)token
                             userName:(nonnull NSString *)userName
                             platform:(nonnull NSString *)platform;


/**
 发布弹幕

 @param danmu 需要发布的弹幕对象
 @param completion 发布回调，失败返回错误信息，成功error为nil
 */
- (void)publishDanmu:(nonnull DanmuAddBean *)danmu
          completion:(void (^_Nullable)(PPYError * _Nullable error))completion;


/**
 获取视频弹幕列表

 @param channelID 视频ID
 @param position 时间单位(0.1秒)，传 0 表示从头开始，第二次请求传上一次返回的 DanmuListBean.end 值
 @param completion block回调，成功 返回弹幕列表，失败 返回错误信息
 */
- (void)getDanmuListWithChannelID:(nonnull NSString *)channelID
                         position:(long)position
                       completion:(void (^_Nullable)(DanmuListBean *_Nullable list, PPYError * _Nullable error))completion;

#pragma mark - 展示弹幕

@property (nonatomic, weak) __nullable id <PPDanmuRendererDelegate> rendererDelegate;
/**
 设置弹幕渲染的view
 */
- (void)setRendererView:(UIView *_Nonnull)view;

/**
 设置弹幕透明度 0-1
 */
@property (nonatomic, assign) CGFloat danmuAlpha;

/**
 设置弹幕显示模式(全屏，半屏)
 */
@property (nonatomic, assign) PPDanmuDisplayMode displayMode;
/**开始渲染弹幕*/
- (void)startDanmu;
/**暂停渲染弹幕*/
- (void)pauseDanmu;
/*停止渲染弹幕*/
- (void)stopDanmu;

//把弹幕展示到 设置的rendererView上
- (void)rendererDanmu:(DanmuContent *_Nonnull)danmu;
@end
