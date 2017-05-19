//
//  PPDanmuPublisher.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/17.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DanmuAddBean,PPYError;
/** 弹幕发布 */
@interface PPDanmuPublisher : NSObject

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
@end
