//
//  PPMessage.h
//  PushMessage
//
//  Created by rockyzhang on 15/7/28.
//  Copyright (c) 2015年 PPTV. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PPMessage : NSObject

@property (nonnull, nonatomic, copy) NSString *tag;
@property (nonnull, nonatomic, copy) NSString *messageID;

@property (nonnull, nonatomic, strong) NSData *data;

@end
