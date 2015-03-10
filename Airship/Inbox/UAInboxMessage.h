/*
 Copyright 2009-2014 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "UADisposable.h"


@class UAInboxMessageList;
@class UAInboxMessage;

typedef void (^UAInboxMessageCallbackBlock)(UAInboxMessage *message);

/**
 * This class represents a Rich Push Inbox message. It contains all
 * the available information about a message, including the URLs where
 * the message can be retrieved.
 */
@interface UAInboxMessage : NSObject

///---------------------------------------------------------------------------------------
/// @name Message Properties
///---------------------------------------------------------------------------------------

/**
 * The Urban Airship message ID.
 * This ID may be used to match an incoming push notification to a specific message.
 */
@property (nonatomic, readonly) NSString *messageID;

/**
 * The URL for the message body itself.
 * This URL may only be accessed with Basic Auth credentials set to the user id and password.
 */
@property (nonatomic, readonly) NSURL *messageBodyURL;

/**
 * The URL for the message.
 * This URL may only be accessed with Basic Auth credentials set to the user id and password.
 */
@property (nonatomic, readonly) NSURL *messageURL;

/**
 * The MIME content type for the message (e.g., text/html).
 */
@property (nonatomic, readonly) NSString *contentType;

/**
 * YES if the message is unread, otherwise NO.
 */
@property (nonatomic, readonly) BOOL unread;

/**
 * YES if the message is deleted, otherwise NO.
 */
@property (nonatomic, readonly) BOOL deleted;

/**
 * The date and time the message was sent (UTC).
 */
@property (nonatomic, readonly) NSDate *messageSent;

/**
 * The date and time the message will expire.
 *
 * A nil value indicates it will never expire.
 */
@property (nonatomic, readonly) NSDate *messageExpiration;

/**
 * The message title.
 */
@property (nonatomic, readonly) NSString *title;

/**
 * The message's extra dictionary. This dictionary can be populated
 * with arbitrary key-value data at the time the message is composed.
 */
@property (nonatomic, readonly) NSDictionary *extra;

/**
 * The raw message dictionary. This is the dictionary that
 * originally created the message.  It can contain more values
 * then the message.
 */
@property (nonatomic, readonly) NSDictionary *rawMessageObject;

/**
 * The parent inbox.
 *
 * Note that this object is not retained by the message.
 */
@property (nonatomic, readonly, weak) UAInboxMessageList *inbox;


/**
 * Mark the message as read.
 *
 * @param completionHandler A block to be executed on completion.
 * @return A UADisposable which can be used to cancel callback execution.
 */
- (UADisposable *)markMessageReadWithCompletionHandler:(UAInboxMessageCallbackBlock)completionHandler;


/**
 * YES if the message is expired, NO otherwise
 */
- (BOOL)isExpired;

@end
