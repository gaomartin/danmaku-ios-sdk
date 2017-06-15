//
//  DanmuBean.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/12.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import "DanmuMessageList.h"

@interface DanmuBean : DanmuContent
@property (nonatomic, assign) long danmuID;// id 弹幕ID
@property (nonatomic, strong) NSString *refName;//弹幕所属标识
@property (nonatomic, assign) NSInteger showTime; //展示时长（秒）
@property (nonatomic, strong) NSString *appplt; //来源设备
@property (nonatomic, strong) NSString *appver; //来源版本

@property (nonatomic, assign) long long createtime;
@property (nonatomic, assign) long upCount;//点赞数
@end
