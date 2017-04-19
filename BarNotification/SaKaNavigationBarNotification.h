//
//  SaKaNavigationBarNotification.h
//  StatusBarNotification
//
//  Created by 撒加 on 17/4/18.
//  Copyright © 2017年 撒加. All rights reserved.
//

#import <UIKit/UIKit.h>
#define kHeight [[UIScreen mainScreen] bounds].size.height
#define kWidth [[UIScreen mainScreen] bounds].size.width
#define kColor(r, g, b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define kFont(n) [UIFont systemFontOfSize:(n)]

@class SaKaNavigationBarNotification;
@protocol SaKaNavigationBarNotificationDelagete <NSObject>
@optional
- (void)navigationBarNotificationWillShow:(SaKaNavigationBarNotification *)notification StartDate:(NSDate *)start;

- (void)navigationBarNotificationIsDismissed:(SaKaNavigationBarNotification *)notification;

- (void)navigationBarNotificationIsTapped:(SaKaNavigationBarNotification *)notification;
@end


@interface SaKaNavigationBarNotification : UIView
/**通知高度*/
@property(nonatomic,assign)CGFloat notificationHeight;
/**通知背景色*/
@property(nonatomic,strong)UIColor *notificationBackgroundColor;
/**字体颜色*/
@property(nonatomic,strong)UIColor *notificationTextColor;
/**自定义view*/
@property(nonatomic,strong)UIView *custormView;
/**开始时间*/
@property(nonatomic,strong,readonly)NSDate *startDate;

@property(nonatomic,assign)id<SaKaNavigationBarNotificationDelagete> delegate;

/**快速创建对象*/
+(instancetype)defaultNavigationBarNotification;
/**原始label型*/
- (void)showWithMessage:(NSString *)message Duration:(CGFloat)duration InView:(__kindof UIScrollView *)scrollView;
/**自定义view型*/
- (void)showCustormViewDuration:(CGFloat)duration InView:(__kindof UIScrollView *)scrollView;
@end
