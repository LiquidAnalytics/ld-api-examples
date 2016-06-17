//
//  LDMDimensionConstants.h
//  LiquidDecisions
//
//  Created by Bryan Nagle on 6/15/13.
//  Copyright (c) 2013 Liquid Analytics. All rights reserved.
//


#define WORKFLOW_PROCESS_STATUS_NEW                         @"/Workflow/processStatus[New]"
#define WORKFLOW_PROCESS_STATUS_EDITING                     @"/Workflow/processStatus[Editing]"
#define WORKFLOW_PROCESS_STATUS_APPROVE                         @"/Workflow/processStatus[Approve]"
#define WORKFLOW_PROCESS_STATUS_VERIFY                         @"/Workflow/processStatus[Verify]"
#define WORKFLOW_PROCESS_STATUS_VERIFIED_ERROR                         @"/Workflow/processStatus[VerifiedError]"
#define WORKFLOW_PROCESS_STATUS_VERIFIED                         @"/Workflow/processStatus[Verified]"
#define WORKFLOW_PROCESS_STATUS_VERIFIED_APPROVE                         @"/Workflow/processStatus[VerifiedApprove]"
#define WORKFLOW_PROCESS_STATUS_REJECTED                         @"/Workflow/processStatus[Rejected]"
#define WORKFLOW_PROCESS_STATUS_SUBMIT                         @"/Workflow/processStatus[Submit]"
#define WORKFLOW_PROCESS_STATUS_SUBMITTED                         @"/Workflow/processStatus[Submitted]"
#define WORKFLOW_PROCESS_STATUS_CUTOFF                         @"/Workflow/processStatus[PastCutoff]"
#define WORKFLOW_PROCESS_STATUS_QUOTED                         @"/Workflow/processStatus[Quoted]"
#define WORKFLOW_PROCESS_STATUS_CANCEL                         @"/Workflow/processStatus[Cancel]"
#define WORKFLOW_PROCESS_STATUS_CANCELLED                      @"/Workflow/processStatus[Cancelled]"

#define WORKFLOW_PROCESS_OVERRIDE_DENIED                       @"/Cart/itemStatus[97]"
#define WORKFLOW_PROCESS_OVERRIDE_PENDING                      @"/Cart/itemStatus[96]"

#define WORKFLOW_PROCESS_CART_TYPE_ORDER                        @"/Workflow/cartType[Order]"
#define WORKFLOW_PROCESS_CART_TYPE_SAMPLE                       @"/Workflow/cartType[Sample]"
#define WORKFLOW_PROCESS_CART_TYPE_PAYMENT                      @"/Workflow/cartType[Payment]"
#define WORKFLOW_PROCESS_CART_TYPE_ADJUSTMENT                   @"/Workflow/cartType[Adjustment]"
#define WORKFLOW_PROCESS_CART_TYPE_QUOTE                        @"/Workflow/cartType[Quote]"

#define PRICE_VALUETYPE_DISCOUNT                                @"/Data/valueType[Discount]"
#define PRICE_OVERRIDE_CURRENCY_FROM_TARGET                     @"/Data/overrideValueType[CurrencyFromTarget]"
#define PRICE_OVERRIDE_CURRENCY                                 @"/Data/overrideValueType[Currency]"
#define PRICE_TYPE_SCALE                                        @"/Price/priceType[Scale]"
#define PRICE_TYPE_NEGOTIATED                                   @"/Price/priceType[Negotiated]"

#define GOAL_RESULT_SUCCESS                                     @"/Goal/result[Success]"
#define GOAL_RESULT_FAIL                                        @"/Goal/result[Fail]"
#define GOAL_RESULT_NOT_STARTED                                 @"/Goal/result[NotStarted]"
#define GOAL_STANDARD_SCORE_YES                                 @"/Goal/standardScore[YES]"
#define GOAL_STANDARD_SCORE_NO                                  @"/Goal/standardScore[NO]"

#define DATA_MEDIATYPE_TEXT                                     @"/Data/mediaType[Text]"
#define DATA_MEDIATYPE_PDF                                     @"/Data/mediaType[PDF]"
#define DATA_MEDIATYPE_VIDEO                                     @"/Data/mediaType[Video]"
#define DATA_MEDIATYPE_AUDIO                                     @"/Data/mediaType[Audio]"
#define DATA_MEDIATYPE_IMAGE                                     @"/Data/mediaType[Image]"

#define DATA_CHART_SALES_HISTORY_UOM_FILTER_LEVEL               @"/Data/uom"

#define FINANCE_ACCOUNTING_ENTRY_TYPE_DEBIT                     @"/Finance/accountingEntryType[Debit]"
#define FINANCE_ACCOUNTING_ENTRY_TYPE_CREDIT                    @"/Finance/accountingEntryType[Credit]"
#define FINANCE_ACCOUNTING_ENTRY_TYPE_PARK_DEBIT                @"/Finance/accountingEntryType[ParkDebit]"
#define FINANCE_ACCOUNTING_ENTRY_TYPE_PARK_CREDIT               @"/Finance/accountingEntryType[ParkCredit]"
#define GLOBAL_CURRENCY_USD                                     @"/Global/currency[USD]"

#define FREE_GOOD                                               @"/Workflow/cartType[Order]/externalItemCategory[FreeGood]"
#define UOM_EACHES                                              @"/Data/uom[EA]";

// BN:  These defies do not appear to be used?
#define NOTIFICATION_TYPE_CANCELED_ORDERS @"/Notification/notificationType[CanceledOrders]"
#define NOTIFICATION_TYPE_REJECTED_ORDERS @"/Notification/notificationType[RejectedOrders]"
#define NOTIFICATION_TYPE_OUT_OF_STOCK @"/Notification/notificationType[OutOfStock]"
#define NOTIFICATION_TYPE_PICK_OMITS @"/Notification/notificationType[PickOmits]"
#define NOTIFICATION_TYPE_TODAYS_DELIVERIES @"/Notification/notificationType[TodaysDeliveries]"
#define NOTIFICATION_TYPE_RETURN_ORDERS @"/Notification/notificationType[ReturnOrders]"
#define NOTIFICATION_TYPE_ORDERS_APPROVALS @"/Notification/notificationType[OrdersApprovals]"
#define NOTIFICATION_TYPE_PRODUCT_NOTIFICATIONS @"/Notification/notificationType[ProductNotifications]"
#define NOTIFICATION_TYPE_CUSTOMER_NOTIFICATIONS @"/Notification/notificationType[CustomerNotifications]"
#define NOTIFICATION_TYPE_USER_NOTIFICATIONS @"/Notification/notificationType[UserNotifications]"
//#define NOTIFICATION_TYPE_OTHER_NOTIFICATIONS @"/Notification/notificationType[OtherNotifications]"

#define SURVEY_ANSWER_TYPE_YESNO @"/Data/answerType[YesNo]"
#define SURVEY_ANSWER_TYPE_MULTISELECT_BUTTON @"/Data/answerType[MultiSelectButtons]"
#define SURVEY_ANSWER_TYPE_MULTISELECT_DIMENSION @"/Data/answerType[MultiSelectDimensions]"
#define SURVEY_ANSWER_TYPE_RADIO_LIST @"/Data/answerType[RadioList]"
#define SURVEY_ANSWER_TYPE_RADIO_LIST_DIMENSION @"/Data/answerType[RadioDimensionsList]"
#define SURVEY_ANSWER_TYPE_SLIDER @"/Data/answerType[OnePointSlider]"
#define SURVEY_ANSWER_TYPE_FREEFORMTEXT @"/Data/answerType[FreeFormText]"
#define SURVEY_ANSWER_TYPE_SUBMIT @"/Data/answerType[Submit]"

#define SURVEY_TYPE_DIRECT @"Direct"
#define SURVEY_TYPE_INDIRECT @"Indirect"

#define ANSWERS_PROCESS_STATUS_SUBMITTED @"/Survey/processStatus[Submitted]"



