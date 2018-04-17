//
//  CZPickerView.h
//
//  Created by chenzeyu on 9/6/15.
//  Copyright (c) 2015 chenzeyu. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CZPickerView;

@protocol CZPickerViewDataSource <NSObject>

@required
/* number of items for picker */
- (NSInteger)numberOfRowsInPickerView:(CZPickerView *)pickerView;

@optional
/*
 Implement at least one of the following method,
 CZPickerView:(CZPickerView *)pickerView
 attributedTitleForRow:(NSInteger)row has higer priority
 */

/* attributed picker item title for each row */
- (NSAttributedString *)czpickerView:(CZPickerView *)pickerView
               attributedTitleForRow:(NSInteger)row;

/* picker item title for each row */
- (NSString *)czpickerView:(CZPickerView *)pickerView
               titleForRow:(NSInteger)row;

/* picker item detail for each row */
- (NSString *)czpickerView:(CZPickerView *)pickerView
              detailForRow:(NSInteger)row;

/* text label color */
- (UIColor *)czpickerView:(CZPickerView *)pickerView
     textLabelColorForRow:(NSInteger)row;

/* detail label color */
- (UIColor *)czpickerView:(CZPickerView *)pickerView
   detailLabelColorForRow:(NSInteger)row;

/* picker item image for each row */
- (UIImage *)czpickerView:(CZPickerView *)pickerView imageForRow:(NSInteger)row;

@end

@protocol CZPickerViewDelegate <NSObject>

@optional

/** delegate method for picking one item */
- (void)czpickerView:(CZPickerView *)pickerView
didConfirmWithItemAtRow:(NSInteger)row;

/*
 delegate method for picking multiple items,
 implement this method if allowMultipleSelection is YES,
 rows is an array of NSNumbers
 */
- (void)czpickerView:(CZPickerView *)pickerView
didConfirmWithItemsAtRows:(NSArray *)rows;

/** delegate method for canceling */
- (void)czpickerViewDidClickCancelButton:(CZPickerView *)pickerView;

/** delegate method for pressing of extra button */
- (void)czpickerViewDidClickExtraButton:(CZPickerView *)pickerView;

/** delegate method for confirming with no row selection */
- (void)czpickerViewDidConfirmWithNoSelection:(CZPickerView *)pickerView;

/* picker will show */
- (void)czpickerViewWillDisplay:(CZPickerView *)pickerView;

/* picker did show */
- (void)czpickerViewDidDisplay:(CZPickerView *)pickerView;

/* picker will dismiss */
- (void)czpickerViewWillDismiss:(CZPickerView *)pickerView;

/* picker did dismiss */
- (void)czpickerViewDidDismiss:(CZPickerView *)pickerView;

@end

@interface CZPickerView : UIView<UITableViewDataSource, UITableViewDelegate>

/** Initialize the picker view with titles
 @param headerTitle The title of header
 @param cancelButtonTitle The title for cancelButton
 @param confirmButtonTitle The title for confirmButton
 */
- (id)initWithHeaderTitle:(NSString *)headerTitle
        cancelButtonTitle:(NSString *)cancelButtonTitle
       confirmButtonTitle:(NSString *)confirmButtonTitle
         extraButtonTitle:(NSString *)extraButtonTitle;

/** show the picker */
- (void)show;
- (void)showInContainer:(id)container;

/** dismiss the picker programmatically */
- (void)dismissDynamic;

/** reload the picker */
- (void)reloadData;

/** return previously selected row, in array of NSNumber form. */
- (NSArray *)selectedRows;

/** set pre-selected rows, rows should be array of NSNumber. */
- (void)setSelectedRows: (NSArray *)rows;

/** unselect all rows */
- (void)unselectAll;

@property id<CZPickerViewDelegate> delegate;

@property id<CZPickerViewDataSource> dataSource;

/** whether to show footer (including confirm and cancel buttons), default NO */
@property BOOL needFooterView;

/** whether allow tap background to dismiss the picker, default YES */
@property BOOL tapBackgroundToDismiss;

/** whether allow selection of multiple items/rows, default NO, if this
 property is YES, then footerView will be shown */
@property BOOL allowMultipleSelection;

/** should cell text wrap **/
@property BOOL cellTextLabelShouldWrap;

/** should we show extra (3rd) button in picker footer **/
@property BOOL showExtraButton;

/** should we show only a single button on picker **/
@property BOOL showSingleButton;

/** picker header background color */
@property (nonatomic, strong) UIColor *headerBackgroundColor;

/** picker header title font */
@property (nonatomic, strong) UIFont *headerTitleFont;

/** picker header title color */
@property (nonatomic, strong) UIColor *headerTitleColor;

/** tableviewcell font */
@property (nonatomic, strong) UIFont *tableViewCellFont;

/** tableviewcell color */
@property (nonatomic, strong) UIColor *tableViewCellColor;

/** tableviewcell detail font **/
@property (nonatomic, strong) UIFont *tableViewCellDetailFont;

/** tableview cell style **/
@property UITableViewCellStyle tableViewCellStyle;

/** tableview row height **/
@property CGFloat tableViewRowHeight;

/** picker cancel button label text font */
@property (nonatomic, strong) UIFont *cancelButtonLabelTextFont;

/** picker cancel button background color */
@property (nonatomic, strong) UIColor *cancelButtonBackgroundColor;

/** picker cancel button normal state color */
@property (nonatomic, strong) UIColor *cancelButtonNormalColor;

/** picker cancel button highlighted state color */
@property (nonatomic, strong) UIColor *cancelButtonHighlightedColor;

/** picker confirm button label text font */
@property (nonatomic, strong) UIFont *confirmButtonLabelTextFont;

/** picker confirm button background color */
@property (nonatomic, strong) UIColor *confirmButtonBackgroundColor;

/** picker confirm button normal state color */
@property (nonatomic, strong) UIColor *confirmButtonNormalColor;

/** picker confirm button highlighted state color */
@property (nonatomic, strong) UIColor *confirmButtonHighlightedColor;

/** picker extra button label text font */
@property (nonatomic, strong) UIFont *extraButtonLabelTextFont;

/** picker extra button background color */
@property (nonatomic, strong) UIColor *extraButtonBackgroundColor;

/** picker extra button normal state color */
@property (nonatomic, strong) UIColor *extraButtonNormalColor;

/** picker extra button highlighted state color */
@property (nonatomic, strong) UIColor *extraButtonHighlightedColor;

/** tint color for tableview, also checkmark color */
@property (nonatomic, strong) UIColor *checkmarkColor;

/** picker's animation duration for showing and dismissing */
@property CGFloat animationDuration;

/** width of picker */
@property CGFloat pickerWidth;

@property UIImage* imageForExtraButton;

@end

