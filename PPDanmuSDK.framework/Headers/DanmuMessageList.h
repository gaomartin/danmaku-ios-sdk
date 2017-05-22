//
//  DanmuMessageList.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/19.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DanmuContent;
@interface DanmuMessageList : NSObject
@property (nonatomic, strong) NSString *name;

@property (nonatomic, strong) NSArray <DanmuContent *>*contents;
@end

@interface DanmuContent : NSObject
@property (nonatomic, strong) NSString *userName;//用户名
@property (nonatomic, strong) NSString *nickName;//昵称
@property (nonatomic, strong) NSString *vipType;//vip标识
@property (nonatomic, strong) NSString *content;//弹幕内容
@property (nonatomic, assign) NSTimeInterval createTime;
@property (nonatomic, strong) NSString *color;//字体颜色
@property (nonatomic, assign) NSInteger size;//字体大小，100 小 200 中  300 大
@property (nonatomic, strong) NSString *font;//字体名
@property (nonatomic, assign) NSInteger position;//字体位置，100从右到左，200顶部居中，300底部居中，400特殊,不传默认为100, 新版100代表顶部，200中部，300下部，400特殊
@property (nonatomic, assign) NSInteger motion;// 0——飘，1——悬停，2——全屏
@property (nonatomic, strong) NSString *facePic;//用户头像

@property (nonatomic, assign) NSInteger isYearVip;//是否年费会员
@property (nonatomic, assign) NSInteger vipGrade;//用户等级
@property (nonatomic, assign) NSInteger character;//弹幕类型 0是非会员，1是会员，2是明星，3是运营
@property (nonatomic, assign) NSInteger playPoint;//播放点
@end
