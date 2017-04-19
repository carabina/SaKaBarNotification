//
//  SaKaNavigationBarNotification.m
//  StatusBarNotification
//
//  Created by 撒加 on 17/4/18.
//  Copyright © 2017年 撒加. All rights reserved.
//

#import "SaKaNavigationBarNotification.h"
@interface SaKaNavigationBarNotification()
@property(nonatomic,assign)CGFloat duration;
@property(nonatomic,weak)UIScrollView *scrollView;
@end
@implementation SaKaNavigationBarNotification

+(instancetype)defaultNavigationBarNotification {
    SaKaNavigationBarNotification *view = [[SaKaNavigationBarNotification alloc]init];
    return view;
}

- (instancetype)init {
    if (self = [super init]) {
        if (self.notificationHeight == 0) {
            self.notificationHeight = 21;
        }
        if (!self.notificationBackgroundColor) {
            self.notificationBackgroundColor = kColor(227, 181, 117);
        }
        if (!self.notificationTextColor) {
            self.notificationTextColor = [UIColor whiteColor];
        }
    }
    return self;
}

- (void)clickOnJump:(UITapGestureRecognizer *)sender {
    [self.delegate navigationBarNotificationIsTapped:self];
}

- (void)showWithMessage:(NSString *)message Duration:(CGFloat)duration InView:(__kindof UIScrollView *)scrollView{
    dispatch_async(dispatch_get_main_queue(), ^{
        self.scrollView = scrollView;
        self.frame = CGRectMake(scrollView.frame.origin.x,scrollView.frame.origin.y, kWidth, self.notificationHeight);
        [scrollView.superview addSubview:self];
        self.backgroundColor = self.notificationBackgroundColor;
        UILabel *titleLabel = [[UILabel alloc] init];
        titleLabel.userInteractionEnabled = YES;
        titleLabel.frame = self.bounds;
        titleLabel.textAlignment = NSTextAlignmentCenter;
        titleLabel.backgroundColor = [UIColor clearColor];
        titleLabel.textColor = self.notificationTextColor;
        titleLabel.font = kFont(12);
        titleLabel.text = message;
        self.duration = duration;
        NSDate* Start = [NSDate date];
        [self setValue:Start forKey:NSStringFromSelector(@selector(startDate))];
        [self.delegate navigationBarNotificationWillShow:self StartDate:Start];
        if (!self.custormView) {
            self.custormView = titleLabel;
        }
        [self addSubview:self.custormView];
        
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(clickOnJump:)];
        self.custormView.userInteractionEnabled = YES;
        [self.custormView addGestureRecognizer:tap];
    });
}

- (void)showCustormViewDuration:(CGFloat)duration InView:(__kindof UIScrollView *)scrollView {
    [self showWithMessage:nil Duration:duration InView:scrollView];
}


- (void)willMoveToSuperview:(UIView *)newSuperview {
    if (!newSuperview) return;
    
    [self.scrollView setContentOffset:CGPointMake(0, -self.notificationHeight) animated:YES];
    
    [self performSelector:@selector(dismiss) withObject:nil afterDelay:1.0f];
}

- (void)dismiss {
    [UIView animateWithDuration:(self.duration-1) animations:^{
        self.alpha = 0;
    } completion:^(BOOL finished) {
        [self.scrollView setContentOffset:CGPointZero animated:YES];
        [self.delegate navigationBarNotificationIsDismissed:self];
        [self removeFromSuperview];
    }];
}




@end
