//
//  DanmuListBean.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/12.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>
@class DanmuBean;
@interface DanmuListBean : NSObject
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray <DanmuBean *>*infos;//弹幕列表
@property (nonatomic, assign) double start; //开始点，单位0.1s
@property (nonatomic, assign) double end; //结束点，单位0.1s
@property (nonatomic, assign) double ts;//下次拉取的间隔时间。单位0.1s
@end
