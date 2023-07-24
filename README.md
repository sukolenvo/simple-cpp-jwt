# Simple JWT decode tool

Tool for decoding JWT payload. **No verification** of the signature or expiry is performed.

# Usage

```bash
$ simple-jwt eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c
{"sub":"1234567890","name":"John Doe","iat":1516239022}
```