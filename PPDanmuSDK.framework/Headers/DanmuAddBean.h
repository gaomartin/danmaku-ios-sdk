//
//  DanmuAddBean.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/12.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, PPDanmuFontSize) {
    PPDanmuFontSizeLittle = 100,
    PPDanmuFontSizeMiddle = 200,
    PPDanmuFontSizeBig = 300
};

typedef NS_ENUM(NSInteger, PPDanmuFontPosition) {
    PPDanmuFontPositionFromRightToLeft = 100,
    PPDanmuFontPositionTopCenter = 200,
    PPDanmuFontPositionBottomCenter = 300,
    PPDanmuFontPositionSpecial = 400
};

typedef NS_ENUM(NSInteger, PPDanmuFontMotion) {
    PPDanmuFontMotionNatant = 0, //漂
    PPDanmuFontMotionStill = 1,//
    PPDanmuFontMotionFullScreen
};

/** 发弹幕 */
@interface DanmuAddBean : NSObject
@property (nonatomic, strong) NSString *ref_name;//弹幕所属标识
@property (nonatomic, strong) NSString *content;//弹幕内容
@property (nonatomic, strong) NSString *attachment;//附加的信息
@property (nonatomic, assign) double play_point; /**<播放点，单位为0.1s*/

@property (nonatomic, strong) NSString *font_color; //字体颜色#FFFFFF
@property (nonatomic, assign) NSInteger font_size; //100 小 200 中  300 大
@property (nonatomic, strong) NSString *font_type; //字体类型
@property (nonatomic, assign) NSInteger font_position;// 100从右到左，200顶部居中，300底部居中，400特殊,不传默认为100  新版100代表顶部，200中部，300下部，400特殊
@property (nonatomic, assign) NSInteger motion;// 0——飘，1——悬停，2——全屏


/**
 初始化方法
 @param channelId 视频channelId
 @param content 弹幕内容
 @param playPoint 播放点，单位为0.1s
 @param fontColor 字体颜色:#FFFFFF
 @param fontName 字体名称
 @param fontSize 字体大小
 @param position 字体出现的位置
 @param motion 字体战士的方式
 */
- (instancetype)initWithChannelId:(NSString *)channelId
                          content:(NSString *)content
                        playPoint:(NSTimeInterval)playPoint
                        fontColor:(NSString *)fontColor
                         fontName:(NSString *)fontName
                         fontSize:(PPDanmuFontSize)fontSize
                     fontPosition:(PPDanmuFontPosition)position
                           motion:(PPDanmuFontMotion)motion;

@end

