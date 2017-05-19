//
//  PPYError.h
//  PPDanmuSDK
//
//  Created by jacksimjia on 2017/5/16.
//  Copyright © 2017年 jacksimjia. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PPYError : NSObject
@property (nonatomic, strong) NSString *message;
@property (nonatomic, assign) NSInteger code;

+ (instancetype)errorWithCode:(NSInteger)code message:(NSString *)message;
@end
