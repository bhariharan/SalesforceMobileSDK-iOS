/*
 Copyright (c) 2012-2014, salesforce.com, inc. All rights reserved.
 
 Redistribution and use of this software in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions
 and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of
 conditions and the following disclaimer in the documentation and/or other materials provided
 with the distribution.
 * Neither the name of salesforce.com, inc. nor the names of its contributors may be used to
 endorse or promote products derived from this software without specific prior written
 permission of salesforce.com, inc.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <SalesforceOAuth/SFOAuthCredentials.h>

/** Constants for the keys available in the community dictionary returned by
 the `communityWithId:` method below. They map to the keys
 returned by the server endpoint /services/data/vXX.X/connect/communities
 */
extern NSString *kCommunityEntityIdKey;
extern NSString *kCommunityNameKey;
extern NSString *kCommunitySiteUrlKey;

/** User account restrictions
 */
typedef NS_OPTIONS(NSUInteger, SFUserAccountAccessRestriction) {
    SFUserAccountAccessRestrictionNone    = 0,
    SFUserAccountAccessRestrictionChatter = 1 << 0,
    SFUserAccountAccessRestrictionREST    = 1 << 1,
    SFUserAccountAccessRestrictionOther   = 1 << 2,
};

/** Class that represents an `account`. An `account` represents
 a user together with the current community it is logged in.
 */
@interface SFUserAccount : NSObject<NSCoding>

@property (nonatomic, copy) NSSet *accessScopes;
@property (nonatomic, strong) SFOAuthCredentials *credentials;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *organizationId;
@property (nonatomic, copy) NSString *organizationName;
@property (nonatomic, copy) NSString *fullName;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic) SFUserAccountAccessRestriction accessRestrictions;

// The current community id the user is logged in
@property (nonatomic, copy) NSString *communityId;

// The list of communities (as dictionary)
@property (nonatomic, copy) NSArray *communities;

/** Designated initializer
 @param identifier The user identifier
 @return the account instance
 */
- (id)initWithIdentifier:(NSString*)identifier;

/** Returns the community dictionary for the specified ID
 */
- (NSDictionary*)communityWithId:(NSString*)communityId;

/** Returns YES if the user has an access token and, presumably,
 a valid session.
 */
- (BOOL)isSessionValid;

@end
